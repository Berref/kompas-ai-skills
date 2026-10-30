# GetMateConstraintObjects - Получить массив зависимых объектов для повторного редактирования детали

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](ipart_getmathematic3d.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_calcmassinertiaproperties.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

LPDISPATCH GetMateConstraintObjects();

Синтаксис COM:

LPENTITYCOLLECTION GetMateConstraintObjects();

Возвращаемое значение:

| \- указатель на интерфейс [ksEntityCollection](ksentitycollection.html) или [IEntityCollection](ksentitycollection.html).  
---|---  
  
Примечание:

Функция работает в сборке. Массив объектов формируется в результате работы функции [UserGetPlacementAndEntity](ksdocument3d_usergetplacementandentity.html) для данной детали. Как правило, на указанные в процессе объекты накладываются сопряжения с объектами данной детали. Если массив сохранить, то при повторном входе в процесс связанные объекты будут выделены.

Подразделы:

(отсутствуют)
