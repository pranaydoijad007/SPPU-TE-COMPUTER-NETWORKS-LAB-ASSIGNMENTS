import socket


print("1. host to ip \n2. ip to host \n3.exit")

choice = input("Enter choice")

if choice == '1':
    name = input("Enter site")

    address = socket.gethostbyname(name)
    print("address = ", address)
elif choice == '2':
    name = input("Enter ip address")
    address=socket.gethostbyaddr(name)
    print("Website = ", address)
else:
    print("Wrong choice")
    exit(0)





