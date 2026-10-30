# Пример регистрации библиотеки-добавления

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
Приведен фрагмент файла экспорта реестра (reg - файла). В данном примере testAddins - название папки библиотеки-добавления. Регистрационная информация добавляется в предопределенный раздел реестра AddIns

Windows Registry Editor Version 5.00

[HKEY_LOCAL_MACHINE\SOFTWARE\ASCON\KOMPAS-3D\AddIns\testAddins]

"AutoConnect"=dword:00000000

"Path"="с:\\\КОМПСАС\\\libs\\\newApiRtw\\\teststep2.rtw"

"FriendlyName"="Test-Addins"

Значения флага AutoConnect = 0 не подключать 1 -подключать библиотеку на старте.
