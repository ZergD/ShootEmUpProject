#!/bin/sh
protoc --proto_path=../Assets --cpp_out=../ ../Assets/Proto/Common/*.proto ../Assets/Proto/Definition/*.proto
protoc --proto_path=../Assets --cpp_out=../ ../Assets/Proto/Common/*.proto ../Assets/Proto/Server/*.proto ../Assets/Proto/Message/*.proto
