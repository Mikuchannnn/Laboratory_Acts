import socket

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(("localhost", 9090))  # Make sure port is the same!
server.listen(1)
print("Server is waiting for connection...")

conn, addr = server.accept()
print("Connected to", addr)
conn.send(b"Hello from server")
conn.close()