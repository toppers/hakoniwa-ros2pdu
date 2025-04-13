uint32 request_id
string service_name
string client_name
uint8 status  # 0=未処理, 1=作業中, 2=キャンセル中, 3=完了
uint8 processing_percentage  # 0～100
int32 result_code  # 0=成功, 非0=失敗（作業中なら EBUSY）
