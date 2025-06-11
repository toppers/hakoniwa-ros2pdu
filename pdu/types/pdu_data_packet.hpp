#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include <cstring>

namespace hako::pdu {

class DataPacket {
private:
    std::string robotName;
    int channelId;
    std::vector<uint8_t> bodyData;

public:
    static constexpr unsigned int DeclarePduForRead = 0x52455044;  // "REPD" (Read Pdu)
    static constexpr unsigned int DeclarePduForWrite = 0x57505044; // "WPPD" (Write Pdu)
    DataPacket() = default;

    // Accessors
    const std::string& GetRobotName() const { return robotName; }
    int GetChannelId() const { return channelId; }
    const std::vector<uint8_t>& GetPduData() const { return bodyData; }

    void SetRobotName(const std::string& name) { robotName = name; }
    void SetChannelId(int id) { channelId = id; }
    void SetBodyData(const std::vector<uint8_t>& data) { bodyData = data; }

    /**
     * Encode this DataPacket into a binary format:
     * [4 bytes] Header length
     * [4 bytes] Robot name length
     * [N bytes] Robot name (UTF-8)
     * [4 bytes] Channel ID
     * [Remaining] Body data
     */
    std::vector<uint8_t> Encode() const {
        std::vector<uint8_t> nameBytes(robotName.begin(), robotName.end());
        int robotNameLength = static_cast<int>(nameBytes.size());
        int headerLength = 4 + robotNameLength + 4;
        int totalLength = 4 + headerLength + static_cast<int>(bodyData.size());

        std::vector<uint8_t> data(totalLength);
        int index = 0;

        auto writeInt = [&](int value) {
            std::memcpy(data.data() + index, &value, 4);
            index += 4;
        };

        writeInt(headerLength);
        writeInt(robotNameLength);
        std::memcpy(data.data() + index, nameBytes.data(), robotNameLength);
        index += robotNameLength;
        writeInt(channelId);

        if (!bodyData.empty()) {
            std::memcpy(data.data() + index, bodyData.data(), bodyData.size());
        }

        return data;
    }

    /**
     * Decode a binary buffer into a DataPacket.
     * Throws std::invalid_argument if format is incorrect.
     */
    static DataPacket Decode(const std::vector<uint8_t>& data) {
        if (data.size() < 12) {
            throw std::invalid_argument("Data too short to be a valid packet.");
        }

        int index = 0;
        auto readInt = [&]() -> int {
            int value;
            std::memcpy(&value, data.data() + index, 4);
            index += 4;
            return value;
        };

        int headerLength = readInt();
        if (data.size() < static_cast<size_t>(4 + headerLength)) {
            throw std::invalid_argument("Header length exceeds actual data size.");
        }

        int robotNameLength = readInt();
        std::string robotName(reinterpret_cast<const char*>(data.data() + index), robotNameLength);
        index += robotNameLength;

        int channelId = readInt();

        std::vector<uint8_t> bodyData;
        if (index < static_cast<int>(data.size())) {
            bodyData.assign(data.begin() + index, data.end());
        }

        DataPacket packet;
        packet.SetRobotName(robotName);
        packet.SetChannelId(channelId);
        packet.SetBodyData(bodyData);
        return packet;
    }
};

} // namespace hako::pdu
