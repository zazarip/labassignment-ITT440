from netmiko import ConnectHandler

myserver = {
    'device_type': 'linux',
    'host':   '192.168.92.3',  #Your Server IP
    'username': 'zarip', #your Server Username
    'password': 'hensem1', #your server password
    'port' : 22,
    'secret': '',
}

net_connect = ConnectHandler(**myserver)
output = net_connect.send_command('uname -a')
print(output)
