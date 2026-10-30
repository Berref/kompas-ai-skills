# Описание необязательных ключей манифеста приложения OnlineHelp и HelpURL

[Инструкция по созданию справки HTML для приложений](help_for_applications.html) > [Онлайн-справка для приложений](online_help.html) |  Scroll [ [ [ ](-web---content-.html "К следующему разделу")](online_help.html "На уровень выше")](online_help.html "К предыдущему разделу")  
---|---  
  
В манифесте приложения содержатся необязательные ключи OnlineHelp и HelpURL, которые служат для работы с онлайн-справкой приложения, см. пример.

<application id="APP_Gayka1" title="Конструкторский элемент на Visual C++ с панелью" appIcon="E00D" helpId="Gayka1" OnlineHelp="true" HelpURL="[www.testhelpserver.ru](http://www.testhelpserver.ru/)" autostart="true" showInMenu="true" iconFont="#Ascon Icons SDK Base" iconAccentFont="#Ascon Icons SDK Accent" iconColor1Font="#Ascon Icons SDK Color1" iconColor2Font="#Ascon Icons SDK Color2" iconColor3Font="#Ascon Icons SDK Color3">

OnLineHelp — признак наличия онлайн-справки у приложения. 

Данный ключ определяет наличие онлайн-справки у приложения.

Принимаемые значения: true или false.

![note](./images/note.png) | Если в настройках КОМПАС-3D установлен вызов онлайн-справки, а на стороне приложения она отсутствует, то необходимо установить в манифесте OnlineHelp=false для локальной работы со справкой.  
---|---  
  
HelpURL — адрес сервера онлайн-справки приложения.

Данный ключ указывает адрес сервера приложения. К URL, определенному в ключе HelpURL манифеста приложения, добавляется на стороне КОМПАС <локаль КОМПАС> и <page>.

Пример работы:

Значение ключа HelpURL="[www.testhelpserver.ru](http://www.testhelpserver.ru/)"

Результирующий URL=[http://www.testshelperver](http://www.testshelperver.ru/ru-RU/cm_gayka5915.html)[.ru/ru-RU/cm_gayka5915.html](http://www.testshelperver.ru/ru-RU/cm_gayka5915.html)

![warn](./images/warn.png) | Ключ HelpURL должен идти в паре с ключом OnlineHelp = true.  
---|---  
  
Примеры работы справки при различных значениях ключей

•КОМПАС-3D онлайн-справка = true, OnlineHelp = отсутствует, HelpURL = отсутствует — справка приложения открывается на [help.ascon.ru](http://help.ascon.ru/);

•КОМПАС-3D онлайн-справка = false, OnlineHelp = отсутствует, HelpURL = отсутствует — справка приложения открывается на локальном сервере с помощью HelpServer;

•КОМПАС-3D онлайн-справка = true, OnlineHelp = true, HelpURL = присутствует и задан — справка открывается на указанном сервере приложения;

•КОМПАС-3D онлайн-справка = true, OnlineHelp = true, HelpURL = отсутствует — справка открывается на [help.ascon.ru](http://help.ascon.ru/);

•КОМПАС-3D онлайн-справка = true, OnlineHelp = false, HelpURL = отсутствует — справка открывается на локальном сервере с помощью HelpServer;

•КОМПАС-3D онлайн-справка = false, OnlineHelp = false, HelpURL = отсутствует — справка открывается на локальном сервере с помощью HelpServer;

•КОМПАС-3D онлайн-справка = false, OnlineHelp = true, HelpURL = отсутствует — справка открывается на локальном сервере с помощью HelpServer, если в процессе работы настройка меняется на КОМПАС-3D онлайн справка = true, то она работает через [help.ascon.ru](http://help.ascon.ru/);

•КОМПАС-3D онлайн-справка = false, OnlineHelp = true, HelpURL = присутствует и задан — справка открывается на локальном сервере с помощью HelpServer, если в процессе работы настройка меняется на КОМПАС-3D онлайн справка = true, то она работает через указанный сервер;

•КОМПАС-3D онлайн-справка = false/true, OnlineHelp = отсутствует, HelpURL = присутствует и задан — некорректное оформление манифеста. HelpURL должен отсутствовать, либо идти в паре с OnlineHelp = true. Работа производится согласно настройке КОМПАС-3D Справка — Использовать онлайн-справку.
