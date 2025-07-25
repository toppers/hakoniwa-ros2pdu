from typing import List

# dependencies for the generated Python class


# class definition for the ROS message
class Time:
    """
    ROS message: builtin_interfaces/Time
    Generated by hakoniwa-ros2pdu.
    """

    sec: int
    nanosec: int

    def __init__(self):
        self.sec = 0
        self.nanosec = 0

    def __str__(self):
        return f"Time(" + ", ".join([
            f"sec={self.sec}"
            f"nanosec={self.nanosec}"
        ]) + ")"

    def __repr__(self):
        return self.__str__()

    def to_dict(self):
        """
        Convert the object to a dictionary.
        """
        d = {}
        # handle field 'sec'
        field_val = self.sec
        if isinstance(field_val, bytearray):
            d['sec'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['sec'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['sec'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['sec'] = field_val
        # handle field 'nanosec'
        field_val = self.nanosec
        if isinstance(field_val, bytearray):
            d['nanosec'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['nanosec'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['nanosec'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['nanosec'] = field_val
        return d

    @classmethod
    def from_dict(cls, d: dict):
        """
        Create an object from a dictionary.
        """
        obj = cls()
        # handle field 'sec'
        if 'sec' in d:
            field_type = cls.__annotations__.get('sec')
            value = d['sec']
            
            if field_type is bytearray:
                obj.sec = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.sec = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.sec = value
            elif hasattr(field_type, 'from_dict'):
                obj.sec = field_type.from_dict(value)
            else:
                obj.sec = value
        # handle field 'nanosec'
        if 'nanosec' in d:
            field_type = cls.__annotations__.get('nanosec')
            value = d['nanosec']
            
            if field_type is bytearray:
                obj.nanosec = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.nanosec = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.nanosec = value
            elif hasattr(field_type, 'from_dict'):
                obj.nanosec = field_type.from_dict(value)
            else:
                obj.nanosec = value
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
