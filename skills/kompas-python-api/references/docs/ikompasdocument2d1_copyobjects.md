# CopyObjects - Копировать объекты

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_createhyperlink.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_clearundo.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

VARIANT CopyObjects( VARIANT Objects,

LPDISPATCH * params );

Синтаксис COM:

HRESULT CopyObjects( VARIANT Objects,

ICopyObjectParam * params,

VARIANT * Result );

Входные параметры:

Objects | \- объект или массив объектов для копирования ( VARIANT типа VT_DISPATCH или VT_ARRAY | VT_DISPATCH ),  
---|---  
params | \- указатель на интерфейс параметров копирования [ICopyObjectParam](icopyobjectparam.html).  
  
Возвращаемое значение:

| Объект или массив копий объектов ( VARIANT типа VT_DISPATCH или VT_ARRAY | VT_DISPATCH ).  
---|---  
  
Примечание:

Метод позволяет создать атрибут по номеру типа атрибута.

Способ копирования зависит от типа интерфейса параметров копирования:

•[ICopyObjectParam](icopyobjectparam.html) \- параметры копирования,

•[ICurveCopyObjectParam](icurvecopyobjectparam.html) \- параметры копирования по кривой,

•[ICircleCopyObjectParam](icirclecopyobjectparam.html) \- параметры копирования по окружности,

•[ICircularCopyObjectParam](icircularcopyobjectparam.html) \- параметры копирования по концентрической сетке,

•[IMeshCopyObjectParam](imeshcopyobjectparam.html) \- параметры копирования по сетке.

Нужный интерфейс параметров копирования можно получить с помощью функции [IKompasDocument1::GetInterface](ikompasdocument1_getinterface.html).

Подразделы:

(отсутствуют)
