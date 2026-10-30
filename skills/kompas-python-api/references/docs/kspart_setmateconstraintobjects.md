# SetMateConstraintObjects - Сохранить в детали зависимые объекты для повторного редактирования детали

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_setmaterial.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_setfilename.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

BOOL SetMateConstraintObjects (LPDISPATCH collection);

Синтаксис COM:

BOOL SetMateConstraintObjects (LPENTITYCOLLECTION collection);

Входной параметр:

collection | \- указатель на интерфейс [ksEntityCollection](ksentitycollection.html) или [IEntityCollection](ksentitycollection.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

Функция работает в сборке. Массив объектов формируется в результате работы процесса [UserGetPlacementAndEntity](ksdocument3d_usergetplacementandentity.html) для данной детали. Как правило, на указанные в процессе объекты накладываются сопряжения с объектами данной детали. Если массив сохранить, то при повторном входе в процесс связанные объекты будут выделены. Если collection = NULL, массив будет взят из документа, который получился после работы процесса UserGetPlacementAndEntity для данной детали.

Подразделы:

(отсутствуют)
