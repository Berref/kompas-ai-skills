# ksGetSystemProfileString - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
char buf[255];

if (ksGetSystemProfileString("Directories", "SYS", buf, 255))

Message(buf);

else

Error("Ключ не найден");
