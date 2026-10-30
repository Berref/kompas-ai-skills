# CanUnloadLibrary - Разрешение на выгрузку библиотеки из памяти

[Создание прикладных библиотек ](libraries_create.html) > [Оформление библиотек типа Converter ](cr95008.html) > [Интерфейс IKompasConverter ](ikompasconverter.html) > [IKompasConverter - свойства ](ikompasconverter_props.html) |  Scroll [ [ [ ](ikompasconverter_converterparameters.html "К следующему разделу")](ikompasconverter_props.html "На уровень выше")](ikompasconverter_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasconverter.html)

Тип данных:BOOL.

Значения свойства:

TRUE | \- библиотеку можно выгружать из памяти,  
---|---  
FALSE | \- библиотеку нельзя выгружать из памяти.  
  
Синтаксис Automation:

CanUnloadLibrary = iObject.CanUnloadLibrary | Получить свойство ([* ](1.html))1  
---|---  
CanUnloadLibrary = iObject.GetCanUnloadLibrary( ) | Получить свойство ([**](2.html))2  
  
Синтаксис COM:

iObject->get_CanUnloadLibrary ( &CanUnloadLibrary ) | Получить свойство.  
---|---  
  
Примечание:

Если внутренний интерфейс параметров захвачен другими пользователями, то библиотеку нельзя выгружать из памяти до тех пор, пока он не освободится. Так как в системе КОМПАС предусмотрена автоматическая выгрузка библиотек, то перед выгрузкой будет вызвана эта функция и библиотека будет выгружена, только если она вернет TRUE.

Подразделы:

(отсутствуют)
