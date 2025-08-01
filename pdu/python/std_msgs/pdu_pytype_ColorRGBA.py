from typing import List

# dependencies for the generated Python class


# class definition for the ROS message
class ColorRGBA:
    """
    ROS message: std_msgs/ColorRGBA
    Generated by hakoniwa-ros2pdu.
    """

    r: float
    g: float
    b: float
    a: float

    def __init__(self):
        self.r = 0.0
        self.g = 0.0
        self.b = 0.0
        self.a = 0.0

    def __str__(self):
        return f"ColorRGBA(" + ", ".join([
            f"r={self.r}"
            f"g={self.g}"
            f"b={self.b}"
            f"a={self.a}"
        ]) + ")"

    def __repr__(self):
        return self.__str__()

    def to_dict(self):
        """
        Convert the object to a dictionary.
        """
        d = {}
        # handle field 'r'
        field_val = self.r
        if isinstance(field_val, bytearray):
            d['r'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['r'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['r'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['r'] = field_val
        # handle field 'g'
        field_val = self.g
        if isinstance(field_val, bytearray):
            d['g'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['g'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['g'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['g'] = field_val
        # handle field 'b'
        field_val = self.b
        if isinstance(field_val, bytearray):
            d['b'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['b'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['b'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['b'] = field_val
        # handle field 'a'
        field_val = self.a
        if isinstance(field_val, bytearray):
            d['a'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['a'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['a'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['a'] = field_val
        return d

    @classmethod
    def from_dict(cls, d: dict):
        """
        Create an object from a dictionary.
        """
        obj = cls()
        # handle field 'r'
        if 'r' in d:
            field_type = cls.__annotations__.get('r')
            value = d['r']
            
            if field_type is bytearray:
                obj.r = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.r = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.r = value
            elif hasattr(field_type, 'from_dict'):
                obj.r = field_type.from_dict(value)
            else:
                obj.r = value
        # handle field 'g'
        if 'g' in d:
            field_type = cls.__annotations__.get('g')
            value = d['g']
            
            if field_type is bytearray:
                obj.g = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.g = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.g = value
            elif hasattr(field_type, 'from_dict'):
                obj.g = field_type.from_dict(value)
            else:
                obj.g = value
        # handle field 'b'
        if 'b' in d:
            field_type = cls.__annotations__.get('b')
            value = d['b']
            
            if field_type is bytearray:
                obj.b = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.b = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.b = value
            elif hasattr(field_type, 'from_dict'):
                obj.b = field_type.from_dict(value)
            else:
                obj.b = value
        # handle field 'a'
        if 'a' in d:
            field_type = cls.__annotations__.get('a')
            value = d['a']
            
            if field_type is bytearray:
                obj.a = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.a = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.a = value
            elif hasattr(field_type, 'from_dict'):
                obj.a = field_type.from_dict(value)
            else:
                obj.a = value
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
