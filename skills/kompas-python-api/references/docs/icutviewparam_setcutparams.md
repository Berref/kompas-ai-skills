# SetCutParams - Установить параметры разреза

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Параметры ](bb2370796.html) > [Интерфейс ICutViewParam ](icutviewparam.html) > [ICutViewParam - методы ](icutviewparam_methods.html) |  Scroll [ [ [ ](icutviewparam_setcutplaneposition.html "К следующему разделу")](icutviewparam_methods.html "На уровень выше")](icutviewparam_getcutplaneposition.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icutviewparam.html)

Синтаксис Automation:

BOOL SetCutParams( long Index,

BSTR Name,

long Number,

BOOL ModelCut )

Синтаксис COM:

HRESULT SetCutParams( long Index,

BSTR Name,

long Number,

BOOL ModelCut,

BOOL * Result );

Входные параметры:

Index | \- индекс разреза,  
---|---  
Name | \- имя разреза,  
Number | \- номер разреза,  
ModelCut | \- признак разреза, TRUE - разрез, FALSE - сечение.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет установить параметры разреза.

Подразделы:

(отсутствуют)
