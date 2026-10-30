# GetCutParams - Получить параметры разреза

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Параметры ](bb2370796.html) > [Интерфейс ICutViewParam ](icutviewparam.html) > [ICutViewParam - методы ](icutviewparam_methods.html) |  Scroll [ [ [ ](icutviewparam_getcutplaneposition.html "К следующему разделу")](icutviewparam_methods.html "На уровень выше")](icutviewparam_deleteallcuts.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icutviewparam.html)

Синтаксис Automation:

LPDISPATCH SetCutParams( long Index,

BSTR * Name,

long * Number,

BOOL * ModelCut )

Синтаксис COM:

HRESULT SetCutParams( long Index,

BSTR * Name,

long * Number,

BOOL * ModelCut,

IDrawingObject ** Contour );

Входные параметры:

Index | \- индекс разреза.  
---|---  
  
Выходные параметры:

Name | \- имя разреза,  
---|---  
Number | \- номер разреза,  
ModelCut | \- признак разреза, TRUE - разрез, FALSE - сечение.  
  
Возвращаемое значение:

| \- Указатель на контур, ограничивающий разрез.  
---|---  
  
Примечание:

Метод позволяет установить параметры разреза.

Подразделы:

(отсутствуют)
