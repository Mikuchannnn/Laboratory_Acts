import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(("localhost", 9090))
message = client.recv(1024)
print(message.decode())
client.close()