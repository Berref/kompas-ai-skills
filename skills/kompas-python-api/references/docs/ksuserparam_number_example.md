# ksUserParam::number - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
Получить номер команды пользовательской библиотеки, при помощи которой

можно редактировать компонент.

//получить интерфейс ksUserParam у KompasObject

ksUserParam userParam( kompasObject.GetParamStruct(ko_UserParam) );

userParam.Init();

//заполнить параметры интерфейса

ksPart.GetUserParam( userParam );

//Получить номер команды

long number = userParam.number;
