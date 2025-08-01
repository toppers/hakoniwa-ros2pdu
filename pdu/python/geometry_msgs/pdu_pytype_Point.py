from typing import List

# dependencies for the generated Python class


# class definition for the ROS message
class Point:
    """
    ROS message: geometry_msgs/Point
    Generated by hakoniwa-ros2pdu.
    """

    x: float
    y: float
    z: float

    def __init__(self):
        self.x = 0.0
        self.y = 0.0
        self.z = 0.0

    def __str__(self):
        return f"Point(" + ", ".join([
            f"x={self.x}"
            f"y={self.y}"
            f"z={self.z}"
        ]) + ")"

    def __repr__(self):
        return self.__str__()

    def to_dict(self):
        """
        Convert the object to a dictionary.
        """
        d = {}
        # handle field 'x'
        field_val = self.x
        if isinstance(field_val, bytearray):
            d['x'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['x'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['x'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['x'] = field_val
        # handle field 'y'
        field_val = self.y
        if isinstance(field_val, bytearray):
            d['y'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['y'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['y'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['y'] = field_val
        # handle field 'z'
        field_val = self.z
        if isinstance(field_val, bytearray):
            d['z'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['z'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['z'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['z'] = field_val
        return d

    @classmethod
    def from_dict(cls, d: dict):
        """
        Create an object from a dictionary.
        """
        obj = cls()
        # handle field 'x'
        if 'x' in d:
            field_type = cls.__annotations__.get('x')
            value = d['x']
            
            if field_type is bytearray:
                obj.x = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.x = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.x = value
            elif hasattr(field_type, 'from_dict'):
                obj.x = field_type.from_dict(value)
            else:
                obj.x = value
        # handle field 'y'
        if 'y' in d:
            field_type = cls.__annotations__.get('y')
            value = d['y']
            
            if field_type is bytearray:
                obj.y = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.y = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.y = value
            elif hasattr(field_type, 'from_dict'):
                obj.y = field_type.from_dict(value)
            else:
                obj.y = value
        # handle field 'z'
        if 'z' in d:
            field_type = cls.__annotations__.get('z')
            value = d['z']
            
            if field_type is bytearray:
                obj.z = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.z = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.z = value
            elif hasattr(field_type, 'from_dict'):
                obj.z = field_type.from_dict(value)
            else:
                obj.z = value
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
