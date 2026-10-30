# factor1 - Признак полного шага вдоль первой оси

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования ](int_copy.html) > [Копия элементов детали по параллелограммной сетке( Интерфейсы ksMeshCopyDefinition и ICopyMeshDefinition) ](ksmeshcopydefinition.html) > [ICopyMeshDefinition - свойства ](ksmeshcopydefinition_props.html) |  Scroll [ [ [ ](ksmeshcopydefinition_factor2.html "К следующему разделу")](ksmeshcopydefinition_props.html "На уровень выше")](ksmeshcopydefinition_count2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmeshcopydefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- свойство [step1](ksmeshcopydefinition_step1.html) устанавливает расстояние между крайними элементами вдоль первой оси,  
---|---  
FALSE | \- свойство step1 устанавливает расстояние между соседними элементами вдоль первой оси.  
  
Синтаксис Automation:

factor1 = iCopyMesh.factor1 | Получить свойство([* ](1.html))  
---|---  
iCopyMesh.factor1 = factor1 | Установить свойство ([* ](1.html))  
factor1 = iCopyMesh.GetFactor1() | Получить свойство ([**](2.html))  
iCopyMesh.SetFactor1(factor1) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
