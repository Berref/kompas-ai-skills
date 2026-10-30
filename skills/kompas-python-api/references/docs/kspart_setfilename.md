# SetFileName - Установить имя файла детали

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_setmateconstraintobjects.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_setadvancedcolor.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

BOOL SetFileName (BSTR name);

Синтаксис COM:

BOOL SetFileName (LPOLESTR name);

Входной параметр:

name | \- полное имя файла детали.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания:

1\. Метод используется для компонентов, вставленных в сборку.

2\. Документ с указанным именем должен существовать.

3\. Компонент не должен быть деталью из библиотеки моделей или стандартным элементом.

4\. Изменение вступает в силу после вызова метода [ksPart::Update](kspart_update.html).

Подразделы:

(отсутствуют)
