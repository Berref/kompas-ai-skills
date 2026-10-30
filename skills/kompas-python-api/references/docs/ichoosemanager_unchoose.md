# Unchoose - Снять выделение объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Подсветка и выделение объектов ](ba1952824.html) > [Интерфейс IChooseManager ](ichoosemanager.html) > [IChooseManager - методы ](ichoosemanager_methods.html) |  Scroll [ [ [ ](ichoosemanager_unchooseall.html "К следующему разделу")](ichoosemanager_methods.html "На уровень выше")](ichoosemanager_ischoosen.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ichoosemanager.html)

Синтаксис Automation:

BOOL Unchoose( VARIANT Objects );

Синтаксис COM:

HRESULT Unchoose( VARIANT Objects,

BOOL * Result );

Входные параметры:

Objects | \- объект или массив объектов, с которых нужно снять выделение ( VARIANT типа VT_DISPATCH или VT_ARRAY | VT_DISPATCH ).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет снять выделение объекта.

Подразделы:

(отсутствуют)
