# ActiveDocument3D - Получить указатель на интерфейс текущего документа трехмерной модели

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_activedocument2d.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksGetActive3dDocument](ksgetactive3ddocument.html).

Синтаксис Automation:

LPDISPATCH ActiveDocument3D();

Возвращаемое значение:

| \- указатель на интерфейс документа трехмерной модели [ksDocument3D](ksdocument3d.html).  
---|---  
  
Синтаксис COM:

Чтобы получить интерфейс текущего документа трехмерной модели при программировании на COM, нужно использовать экспортную функцию LPDOCUMENT3D ksGetActive3dDocument();

Возвращаемое значение:

| \- указатель на интерфейс документа трехмерной модели [IDocument3D](ksdocument3d.html).  
---|---  
  
Примечание:

Если документ трехмерной модели не активен, функция возвращает NULL.

Подразделы:

(отсутствуют)
