# ResModule - Модуль с описанием пользовательской спецпанели

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IProcessParam ](iprocessparam.html) > [IProcessParam - свойства ](iprocessparam_props.html) |  Scroll [ [ [ ](iprocessparam_showcommandwindow.html "К следующему разделу")](iprocessparam_props.html "На уровень выше")](iprocessparam_propertytabs.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocessparam.html)

Тип данных:VARIANT (long или BSTR).

Синтаксис Automation:

ResModule = iObject.ResModule | Получить свойство ([* ](1.html))  
---|---  
iObject.ResModule = ResModule | Установить свойство ([* ](1.html))  
ResModule = iObject.GetResModule() | Получить свойство([**](2.html))  
iObject.SetResModule(ResModule) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ResModule(&ResModule) | Получить свойство  
---|---  
iObject->put_ResModule(ResModule) | Установить свойство  
  
Значение свойства:

HINSTANCE (тип значения long)

\- полный путь к файлу (тип значения BSTR) dll-модуля, в котором находятся все необходимые ресурсы.

Примечание:

Данное свойство позволяет установить или получить dll-модуль, в котором находится описание пользовательской спецпанели, рисунки для пользовательских кнопок (см. [IProcessParam::SpecToolbarEx](iprocessparam_spectoolbarex.html) и [IProcessParam::BmpBeginID](iprocessparam_bmpbeginid.html)).

Подразделы:

(отсутствуют)
