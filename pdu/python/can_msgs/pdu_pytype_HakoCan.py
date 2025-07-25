from typing import List

# dependencies for the generated Python class
from ..can_msgs.pdu_pytype_HakoCanBody import HakoCanBody
from ..can_msgs.pdu_pytype_HakoCanHead import HakoCanHead


# class definition for the ROS message
class HakoCan:
    """
    ROS message: can_msgs/HakoCan
    Generated by hakoniwa-ros2pdu.
    """

    head: HakoCanHead
    body: HakoCanBody

    def __init__(self):
        self.head = HakoCanHead()
        self.body = HakoCanBody()

    def __str__(self):
        return f"HakoCan(" + ", ".join([
            f"head={self.head}"
            f"body={self.body}"
        ]) + ")"

    def __repr__(self):
        return self.__str__()

    def to_dict(self):
        """
        Convert the object to a dictionary.
        """
        d = {}
        # handle field 'head'
        field_val = self.head
        if isinstance(field_val, bytearray):
            d['head'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['head'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['head'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['head'] = field_val
        # handle field 'body'
        field_val = self.body
        if isinstance(field_val, bytearray):
            d['body'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['body'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['body'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['body'] = field_val
        return d

    @classmethod
    def from_dict(cls, d: dict):
        """
        Create an object from a dictionary.
        """
        obj = cls()
        # handle field 'head'
        if 'head' in d:
            field_type = cls.__annotations__.get('head')
            value = d['head']
            
            if field_type is bytearray:
                obj.head = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.head = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.head = value
            elif hasattr(field_type, 'from_dict'):
                obj.head = field_type.from_dict(value)
            else:
                obj.head = value
        # handle field 'body'
        if 'body' in d:
            field_type = cls.__annotations__.get('body')
            value = d['body']
            
            if field_type is bytearray:
                obj.body = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.body = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.body = value
            elif hasattr(field_type, 'from_dict'):
                obj.body = field_type.from_dict(value)
            else:
                obj.body = value
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
