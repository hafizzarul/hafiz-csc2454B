socket = require('socket')
port = 3030
server = socket.bind('*',port)
io.write("Listening to port "..port.."\n")
sv = server:accept()
io.write("Connection Established\n")
while true do 

	msg = sv:receive()
	io.write("Message from Client > " .. msg .. "\n")
	io.write("Messsage to Client  > ")
	sv:send(io.read() .. "\n")
end
io.read()
