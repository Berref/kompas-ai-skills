# SetMaterial - Установить материал детали

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_setobject.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_setmateconstraintobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

BOOL SetMaterial (BSTR name,

double density);

Синтаксис COM:

BOOL SetMaterial (LPOLESTR name,

double density);

Входные параметры:

name | \- название материала,  
---|---  
density | \- плотность материала (г/куб.см).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания:

1\. Компонент, у которого меняется материал, должен быть деталью.

2\. Компонент не должен быть деталью из библиотеки моделей или стандартным элементом.

3\. Метод используется в детали для верхнего компонента, в сборках - для вставленных деталей.

4\. Изменение материала вступает в силу после вызова метода [ksPart::Update](kspart_update.html).

Подразделы:

(отсутствуют)
