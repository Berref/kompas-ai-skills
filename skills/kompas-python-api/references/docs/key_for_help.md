# Ключ манифеста приложения helpId

[Инструкция по созданию справки HTML для приложений](help_for_applications.html) > [Локальная справка для приложений](local_help.html) |  Scroll [ [ [ ](name_for_ini.html "К следующему разделу")](local_help.html "На уровень выше")](local_help.html "К предыдущему разделу")  
---|---  
  
В манифесте приложения содержится необязательный ключ helpId, который задает имя справочной системы приложения. Данный ключ служит для задания синонима имени справки и ключа "app id", который задан GUID'ом. Ключ манифеста является НЕ обязательным. Располагать его следует между appIcon и autostart.

Пример:

<application id="APP_Gayka1" title="Конструкторский элемент на Visual C++ с панелью" appIcon="E00D" helpId="Gayka1" autostart="true" showInMenu="true" iconFont="#Ascon Icons SDK Base" iconAccentFont="#Ascon Icons SDK Accent" iconColor1Font="#Ascon Icons SDK Color1" iconColor2Font="#Ascon Icons SDK Color2" iconColor3Font="#Ascon Icons SDK Color3">
