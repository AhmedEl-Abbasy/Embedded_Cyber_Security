# SECURE_DIAGNOSTICS

###### Send Service 31, sub service 01 and routine AA00 to turn on led
###### If we send routine without having security access we will receive NRC 7F 31 35
###### If we have security access we will receive 7101AA00 and led will be on


##### Routine for security access 
###### Send 2701 with UART -> Received 6701(4 random bytes )
###### Encrypt 4 random bytes with symmetric key
###### Send 2702 ( 4 encrypted bytes )

https://github.com/AhmedEl-Abbasy/Embedded_Cyber_Security/assets/60989466/ffc69374-90a6-4761-8ed5-4c2e0957b0dd


