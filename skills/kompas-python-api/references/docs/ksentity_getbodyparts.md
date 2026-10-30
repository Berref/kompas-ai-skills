# GetBodyParts - Получить указатель на интерфейс частей тела

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [ksEntity - методы ](ksentity_methods.html) |  Scroll [ [ [ ](ksentity_getdefinition.html "К следующему разделу")](ksentity_methods.html "На уровень выше")](ksentity_getadvancedcolor.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksentity.html)

Синтаксис Automation:

LPBODYPARTS GetBodyParts();

Синтаксис COM:

LPDISPATCH GetBodyParts();

Возвращаемое значение:

указатель на интерфейс массива тел [ksBodyParts](ksbodyparts.html) или [IBodyParts](ksbodyparts.html). | \- если объект состоит из частей,  
---|---  
NULL | \- если объект не имеет частей.  
  
Примечание:o

Метод позволяет получить интерфейс частей тела. Если объект не имеет частей, то метод вернет NULL. Части тела могут быть у операций вырезания.

Подразделы:

(отсутствуют)
