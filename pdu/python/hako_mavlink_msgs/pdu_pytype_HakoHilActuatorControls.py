from typing import List

# dependencies for the generated Python class


# class definition for the ROS message
class HakoHilActuatorControls:
    """
    ROS message: hako_mavlink_msgs/HakoHilActuatorControls
    Generated by hakoniwa-ros2pdu.
    """

    time_usec: int
    controls: List[float]
    mode: int
    flags: int

    def __init__(self):
        self.time_usec = 0
        self.controls = []
        self.mode = 0
        self.flags = 0

    def __str__(self):
        return f"HakoHilActuatorControls(" + ", ".join([
            f"time_usec={self.time_usec}"
            f"controls={self.controls}"
            f"mode={self.mode}"
            f"flags={self.flags}"
        ]) + ")"

    def __repr__(self):
        return self.__str__()

    def to_dict(self):
        """
        Convert the object to a dictionary.
        """
        d = {}
        # handle field 'time_usec'
        field_val = self.time_usec
        if isinstance(field_val, bytearray):
            d['time_usec'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['time_usec'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['time_usec'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['time_usec'] = field_val
        # handle field 'controls'
        field_val = self.controls
        if isinstance(field_val, bytearray):
            d['controls'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['controls'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['controls'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['controls'] = field_val
        # handle field 'mode'
        field_val = self.mode
        if isinstance(field_val, bytearray):
            d['mode'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['mode'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['mode'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['mode'] = field_val
        # handle field 'flags'
        field_val = self.flags
        if isinstance(field_val, bytearray):
            d['flags'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['flags'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['flags'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['flags'] = field_val
        return d

    @classmethod
    def from_dict(cls, d: dict):
        """
        Create an object from a dictionary.
        """
        obj = cls()
        # handle field 'time_usec'
        if 'time_usec' in d:
            field_type = cls.__annotations__.get('time_usec')
            value = d['time_usec']
            
            if field_type is bytearray:
                obj.time_usec = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.time_usec = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.time_usec = value
            elif hasattr(field_type, 'from_dict'):
                obj.time_usec = field_type.from_dict(value)
            else:
                obj.time_usec = value
        # handle field 'controls'
        if 'controls' in d:
            field_type = cls.__annotations__.get('controls')
            value = d['controls']
            
            if field_type is bytearray:
                obj.controls = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.controls = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.controls = value
            elif hasattr(field_type, 'from_dict'):
                obj.controls = field_type.from_dict(value)
            else:
                obj.controls = value
        # handle field 'mode'
        if 'mode' in d:
            field_type = cls.__annotations__.get('mode')
            value = d['mode']
            
            if field_type is bytearray:
                obj.mode = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.mode = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.mode = value
            elif hasattr(field_type, 'from_dict'):
                obj.mode = field_type.from_dict(value)
            else:
                obj.mode = value
        # handle field 'flags'
        if 'flags' in d:
            field_type = cls.__annotations__.get('flags')
            value = d['flags']
            
            if field_type is bytearray:
                obj.flags = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.flags = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.flags = value
            elif hasattr(field_type, 'from_dict'):
                obj.flags = field_type.from_dict(value)
            else:
                obj.flags = value
        return obj

    def to_json(self, indent=2):
        """
        Convert the object to a JSON string.
        """
        import json
        return json.dumps(self.to_dict(), indent=indent)

    @classmethod
    def from_json(cls, json_str: str):
        """
        Create an object from a JSON string.
        """
        import json
        return cls.from_dict(json.loads(json_str))
