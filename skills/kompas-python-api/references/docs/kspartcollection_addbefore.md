# AddBefore - Добавить в массив компонент перед указанным компонентом

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Массив компонентов сборки (Интерфейсы ksPartCollection и IPartCollection) ](kspartcollection.html) > [ksPartCollection - методы ](kspartcollection_methods.html) |  Scroll [ [ [ ](kspartcollection_clear.html "К следующему разделу")](kspartcollection_methods.html "На уровень выше")](kspartcollection_addat.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspartcollection.html)

Синтаксис Automation:

BOOL AddBefore (LPDISPATCH entity,

LPDISPATCH base);

Синтаксис COM:

BOOL AddBefore (LPPART entity,

LPPART base);

Входные параметры:

part | \- указатель на интерфейс добавляемого компонента [ksPart](kspart.html) или[IPart](kspart.html),  
---|---  
base | \- указатель на интерфейс компонента базового объекта [ksPart](kspart.html) или [IPart](kspart.html).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
