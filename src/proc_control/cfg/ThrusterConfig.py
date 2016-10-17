## *********************************************************
## 
## File autogenerated for the proc_control package 
## by the dynamic_reconfigure package.
## Please do not edit.
## 
## ********************************************************/

from dynamic_reconfigure.encoding import extract_params

inf = float('inf')

config_description = {'upper': 'DEFAULT', 'lower': 'groups', 'srcline': 233, 'name': 'Default', 'parent': 0, 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'cstate': 'true', 'parentname': 'Default', 'class': 'DEFAULT', 'field': 'default', 'state': True, 'parentclass': '', 'groups': [], 'parameters': [{'srcline': 259, 'description': 'Port: The force in X', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Port_X', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Port: The force in Y', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Port_Y', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Port: The force in Z', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Port_Z', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Port: The force in YAW', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Port_YAW', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Port: The force in PITCH', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Port_PITCH', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Port: The force in ROLL', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Port_ROLL', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Starboard: The force in X', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Starboard_X', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Starboard: The force in Y', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Starboard_Y', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Starboard: The force in Z', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Starboard_Z', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Starboard: The force in YAW', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Starboard_YAW', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Starboard: The force in PITCH', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Starboard_PITCH', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Starboard: The force in ROLL', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Starboard_ROLL', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Front_Depth: The force in X', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Front_Depth_X', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Front_Depth: The force in Y', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Front_Depth_Y', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Front_Depth: The force in Z', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Front_Depth_Z', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Front_Depth: The force in YAW', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Front_Depth_YAW', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Front_Depth: The force in PITCH', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Front_Depth_PITCH', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Front_Depth: The force in ROLL', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Front_Depth_ROLL', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Back_Depth: The force in X', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Back_Depth_X', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Back_Depth: The force in Y', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Back_Depth_Y', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Back_Depth: The force in Z', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Back_Depth_Z', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Back_Depth: The force in YAW', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Back_Depth_YAW', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Back_Depth: The force in PITCH', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Back_Depth_PITCH', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Back_Depth: The force in ROLL', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Back_Depth_ROLL', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Front_Heading: The force in X', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Front_Heading_X', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Front_Heading: The force in Y', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Front_Heading_Y', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Front_Heading: The force in Z', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Front_Heading_Z', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Front_Heading: The force in YAW', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Front_Heading_YAW', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Front_Heading: The force in PITCH', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Front_Heading_PITCH', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Front_Heading: The force in ROLL', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Front_Heading_ROLL', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Back_Heading: The force in X', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Back_Heading_X', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Back_Heading: The force in Y', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Back_Heading_Y', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Back_Heading: The force in Z', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Back_Heading_Z', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Back_Heading: The force in YAW', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Back_Heading_YAW', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Back_Heading: The force in PITCH', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Back_Heading_PITCH', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}, {'srcline': 259, 'description': 'Back_Heading: The force in ROLL', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py', 'name': 'Back_Heading_ROLL', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': -100.0, 'type': 'double'}], 'type': '', 'id': 0}

min = {}
max = {}
defaults = {}
level = {}
type = {}
all_level = 0

#def extract_params(config):
#    params = []
#    params.extend(config['parameters'])    
#    for group in config['groups']:
#        params.extend(extract_params(group))
#    return params

for param in extract_params(config_description):
    min[param['name']] = param['min']
    max[param['name']] = param['max']
    defaults[param['name']] = param['default']
    level[param['name']] = param['level']
    type[param['name']] = param['type']
    all_level = all_level | param['level']
