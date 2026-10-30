# AddAt - Добавить в массив компонент с заданным индексом

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Массив компонентов сборки (Интерфейсы ksPartCollection и IPartCollection) ](kspartcollection.html) > [ksPartCollection - методы ](kspartcollection_methods.html) |  Scroll [ [ [ ](kspartcollection_addbefore.html "К следующему разделу")](kspartcollection_methods.html "На уровень выше")](kspartcollection_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspartcollection.html)

Синтаксис Automation:

BOOL AddAt (LPDISPATCH part,

long index);

Синтаксис COM:

BOOL AddAt (LPPART part,

unsigned long index);

Входные параметры:

part | \- указатель на интерфейс компонента [ksPart](kspart.html) или [IPart](kspart.html),  
---|---  
index | \- индекс в массиве.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
