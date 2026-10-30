# GetAreaEx - Получить площадь грани (ST_MIX_MM..ST_MIX_M единицы измерения)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Грань (Интерфейсы ksFaceDefinition, IFaceDefinition) ](ksfacedefinition.html) > [IFaceDefinition - методы ](ksfacedefinition_methods.html) |  Scroll [ [ [ ](ksfacedefinition_getcylinderparam.html "К следующему разделу")](ksfacedefinition_methods.html "На уровень выше")](ksfacedefinition_getarea.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksfacedefinition.html)

Синтаксис Automation:

double GetAreaEx( long bitVector, double angleTolerance );

Синтаксис COM:

double GetAreaEx (unsigned long bitVector, double angleTolerance );

Входные параметры:

bitVector | \- [единицы измерения](lentypes.html),  
---|---  
angleTolerance | \- ограничение углового отклонения при аппроксимации оболочки треугольными пластинами.  
  
Возвращаемое значение:

площадь грани | \- в случае успешного завершения.  
---|---  
0 | \- в случае неудачи.  
  
Версия Компас v21

Подразделы:

(отсутствуют)
