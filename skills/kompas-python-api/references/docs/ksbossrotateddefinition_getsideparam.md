# GetSideParam - Получить параметры вращения в одном направлении

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Приклеееный элемент вращения (Интерфейс ksBossRotatedDefinition, IBossRotatedDefinition) ](ksbossrotateddefinition.html) > [IBossRotatedDefinition - методы ](ksbossrotateddefinition_methods.html) |  Scroll [ [ [ ](ksbossrotateddefinition_getthinparam.html "К следующему разделу")](ksbossrotateddefinition_methods.html "На уровень выше")](ksbossrotateddefinition_getsketch.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksbossrotateddefinition.html)

Синтаксис Automation:

BOOL GetSideParam (BOOL forward,

double *angle);

Синтаксис COM:

BOOL GetSideParam (BOOL forward,

double * angle);

Входной параметр:

forward | \- направление вращения: TRUE - прямое, FALSE - обратное.  
---|---  
  
Выходной параметр:

angle | \- угол вращения.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
