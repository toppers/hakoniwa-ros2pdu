from typing import List

# dependencies for the generated Python class


# class definition for the ROS message
class HakoHilSensor:
    """
    ROS message: hako_mavlink_msgs/HakoHilSensor
    Generated by hakoniwa-ros2pdu.
    """

    time_usec: int
    xacc: float
    yacc: float
    zacc: float
    xgyro: float
    ygyro: float
    zgyro: float
    xmag: float
    ymag: float
    zmag: float
    abs_pressure: float
    diff_pressure: float
    pressure_alt: float
    temperature: float
    fields_updated: int
    id: int

    def __init__(self):
        self.time_usec = 0
        self.xacc = 0.0
        self.yacc = 0.0
        self.zacc = 0.0
        self.xgyro = 0.0
        self.ygyro = 0.0
        self.zgyro = 0.0
        self.xmag = 0.0
        self.ymag = 0.0
        self.zmag = 0.0
        self.abs_pressure = 0.0
        self.diff_pressure = 0.0
        self.pressure_alt = 0.0
        self.temperature = 0.0
        self.fields_updated = 0
        self.id = 0

    def __str__(self):
        return f"HakoHilSensor(" + ", ".join([
            f"time_usec={self.time_usec}"
            f"xacc={self.xacc}"
            f"yacc={self.yacc}"
            f"zacc={self.zacc}"
            f"xgyro={self.xgyro}"
            f"ygyro={self.ygyro}"
            f"zgyro={self.zgyro}"
            f"xmag={self.xmag}"
            f"ymag={self.ymag}"
            f"zmag={self.zmag}"
            f"abs_pressure={self.abs_pressure}"
            f"diff_pressure={self.diff_pressure}"
            f"pressure_alt={self.pressure_alt}"
            f"temperature={self.temperature}"
            f"fields_updated={self.fields_updated}"
            f"id={self.id}"
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
        # handle field 'xacc'
        field_val = self.xacc
        if isinstance(field_val, bytearray):
            d['xacc'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['xacc'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['xacc'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['xacc'] = field_val
        # handle field 'yacc'
        field_val = self.yacc
        if isinstance(field_val, bytearray):
            d['yacc'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['yacc'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['yacc'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['yacc'] = field_val
        # handle field 'zacc'
        field_val = self.zacc
        if isinstance(field_val, bytearray):
            d['zacc'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['zacc'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['zacc'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['zacc'] = field_val
        # handle field 'xgyro'
        field_val = self.xgyro
        if isinstance(field_val, bytearray):
            d['xgyro'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['xgyro'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['xgyro'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['xgyro'] = field_val
        # handle field 'ygyro'
        field_val = self.ygyro
        if isinstance(field_val, bytearray):
            d['ygyro'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['ygyro'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['ygyro'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['ygyro'] = field_val
        # handle field 'zgyro'
        field_val = self.zgyro
        if isinstance(field_val, bytearray):
            d['zgyro'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['zgyro'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['zgyro'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['zgyro'] = field_val
        # handle field 'xmag'
        field_val = self.xmag
        if isinstance(field_val, bytearray):
            d['xmag'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['xmag'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['xmag'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['xmag'] = field_val
        # handle field 'ymag'
        field_val = self.ymag
        if isinstance(field_val, bytearray):
            d['ymag'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['ymag'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['ymag'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['ymag'] = field_val
        # handle field 'zmag'
        field_val = self.zmag
        if isinstance(field_val, bytearray):
            d['zmag'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['zmag'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['zmag'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['zmag'] = field_val
        # handle field 'abs_pressure'
        field_val = self.abs_pressure
        if isinstance(field_val, bytearray):
            d['abs_pressure'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['abs_pressure'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['abs_pressure'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['abs_pressure'] = field_val
        # handle field 'diff_pressure'
        field_val = self.diff_pressure
        if isinstance(field_val, bytearray):
            d['diff_pressure'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['diff_pressure'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['diff_pressure'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['diff_pressure'] = field_val
        # handle field 'pressure_alt'
        field_val = self.pressure_alt
        if isinstance(field_val, bytearray):
            d['pressure_alt'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['pressure_alt'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['pressure_alt'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['pressure_alt'] = field_val
        # handle field 'temperature'
        field_val = self.temperature
        if isinstance(field_val, bytearray):
            d['temperature'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['temperature'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['temperature'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['temperature'] = field_val
        # handle field 'fields_updated'
        field_val = self.fields_updated
        if isinstance(field_val, bytearray):
            d['fields_updated'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['fields_updated'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['fields_updated'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['fields_updated'] = field_val
        # handle field 'id'
        field_val = self.id
        if isinstance(field_val, bytearray):
            d['id'] = list(field_val)
        elif hasattr(field_val, 'to_dict'):
            d['id'] = field_val.to_dict()
        elif isinstance(field_val, list):
            d['id'] = [item.to_dict() if hasattr(item, 'to_dict') else item for item in field_val]
        else:
            d['id'] = field_val
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
        # handle field 'xacc'
        if 'xacc' in d:
            field_type = cls.__annotations__.get('xacc')
            value = d['xacc']
            
            if field_type is bytearray:
                obj.xacc = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.xacc = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.xacc = value
            elif hasattr(field_type, 'from_dict'):
                obj.xacc = field_type.from_dict(value)
            else:
                obj.xacc = value
        # handle field 'yacc'
        if 'yacc' in d:
            field_type = cls.__annotations__.get('yacc')
            value = d['yacc']
            
            if field_type is bytearray:
                obj.yacc = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.yacc = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.yacc = value
            elif hasattr(field_type, 'from_dict'):
                obj.yacc = field_type.from_dict(value)
            else:
                obj.yacc = value
        # handle field 'zacc'
        if 'zacc' in d:
            field_type = cls.__annotations__.get('zacc')
            value = d['zacc']
            
            if field_type is bytearray:
                obj.zacc = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.zacc = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.zacc = value
            elif hasattr(field_type, 'from_dict'):
                obj.zacc = field_type.from_dict(value)
            else:
                obj.zacc = value
        # handle field 'xgyro'
        if 'xgyro' in d:
            field_type = cls.__annotations__.get('xgyro')
            value = d['xgyro']
            
            if field_type is bytearray:
                obj.xgyro = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.xgyro = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.xgyro = value
            elif hasattr(field_type, 'from_dict'):
                obj.xgyro = field_type.from_dict(value)
            else:
                obj.xgyro = value
        # handle field 'ygyro'
        if 'ygyro' in d:
            field_type = cls.__annotations__.get('ygyro')
            value = d['ygyro']
            
            if field_type is bytearray:
                obj.ygyro = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.ygyro = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.ygyro = value
            elif hasattr(field_type, 'from_dict'):
                obj.ygyro = field_type.from_dict(value)
            else:
                obj.ygyro = value
        # handle field 'zgyro'
        if 'zgyro' in d:
            field_type = cls.__annotations__.get('zgyro')
            value = d['zgyro']
            
            if field_type is bytearray:
                obj.zgyro = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.zgyro = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.zgyro = value
            elif hasattr(field_type, 'from_dict'):
                obj.zgyro = field_type.from_dict(value)
            else:
                obj.zgyro = value
        # handle field 'xmag'
        if 'xmag' in d:
            field_type = cls.__annotations__.get('xmag')
            value = d['xmag']
            
            if field_type is bytearray:
                obj.xmag = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.xmag = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.xmag = value
            elif hasattr(field_type, 'from_dict'):
                obj.xmag = field_type.from_dict(value)
            else:
                obj.xmag = value
        # handle field 'ymag'
        if 'ymag' in d:
            field_type = cls.__annotations__.get('ymag')
            value = d['ymag']
            
            if field_type is bytearray:
                obj.ymag = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.ymag = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.ymag = value
            elif hasattr(field_type, 'from_dict'):
                obj.ymag = field_type.from_dict(value)
            else:
                obj.ymag = value
        # handle field 'zmag'
        if 'zmag' in d:
            field_type = cls.__annotations__.get('zmag')
            value = d['zmag']
            
            if field_type is bytearray:
                obj.zmag = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.zmag = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.zmag = value
            elif hasattr(field_type, 'from_dict'):
                obj.zmag = field_type.from_dict(value)
            else:
                obj.zmag = value
        # handle field 'abs_pressure'
        if 'abs_pressure' in d:
            field_type = cls.__annotations__.get('abs_pressure')
            value = d['abs_pressure']
            
            if field_type is bytearray:
                obj.abs_pressure = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.abs_pressure = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.abs_pressure = value
            elif hasattr(field_type, 'from_dict'):
                obj.abs_pressure = field_type.from_dict(value)
            else:
                obj.abs_pressure = value
        # handle field 'diff_pressure'
        if 'diff_pressure' in d:
            field_type = cls.__annotations__.get('diff_pressure')
            value = d['diff_pressure']
            
            if field_type is bytearray:
                obj.diff_pressure = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.diff_pressure = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.diff_pressure = value
            elif hasattr(field_type, 'from_dict'):
                obj.diff_pressure = field_type.from_dict(value)
            else:
                obj.diff_pressure = value
        # handle field 'pressure_alt'
        if 'pressure_alt' in d:
            field_type = cls.__annotations__.get('pressure_alt')
            value = d['pressure_alt']
            
            if field_type is bytearray:
                obj.pressure_alt = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.pressure_alt = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.pressure_alt = value
            elif hasattr(field_type, 'from_dict'):
                obj.pressure_alt = field_type.from_dict(value)
            else:
                obj.pressure_alt = value
        # handle field 'temperature'
        if 'temperature' in d:
            field_type = cls.__annotations__.get('temperature')
            value = d['temperature']
            
            if field_type is bytearray:
                obj.temperature = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.temperature = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.temperature = value
            elif hasattr(field_type, 'from_dict'):
                obj.temperature = field_type.from_dict(value)
            else:
                obj.temperature = value
        # handle field 'fields_updated'
        if 'fields_updated' in d:
            field_type = cls.__annotations__.get('fields_updated')
            value = d['fields_updated']
            
            if field_type is bytearray:
                obj.fields_updated = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.fields_updated = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.fields_updated = value
            elif hasattr(field_type, 'from_dict'):
                obj.fields_updated = field_type.from_dict(value)
            else:
                obj.fields_updated = value
        # handle field 'id'
        if 'id' in d:
            field_type = cls.__annotations__.get('id')
            value = d['id']
            
            if field_type is bytearray:
                obj.id = bytearray(value)
            elif hasattr(field_type, '__origin__') and field_type.__origin__ is list:
                list_item_type = field_type.__args__[0]
                if hasattr(list_item_type, 'from_dict'):
                    obj.id = [list_item_type.from_dict(item) for item in value]
                else:
                    obj.id = value
            elif hasattr(field_type, 'from_dict'):
                obj.id = field_type.from_dict(value)
            else:
                obj.id = value
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
