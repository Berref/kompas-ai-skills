# insideFlag - Признак наличия копий внутри сетки

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования ](int_copy.html) > [Копия элементов детали по параллелограммной сетке( Интерфейсы ksMeshCopyDefinition и ICopyMeshDefinition) ](ksmeshcopydefinition.html) > [ICopyMeshDefinition - свойства ](ksmeshcopydefinition_props.html) |  Scroll [ [ [ ](ksmeshcopydefinition_step1.html "К следующему разделу")](ksmeshcopydefinition_props.html "На уровень выше")](ksmeshcopydefinition_geomarray.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmeshcopydefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- оставлять копии во всех узлах сетки,  
---|---  
FALSE | \- оставлять копии по периметру сетки.  
  
Синтаксис Automation:

insideFlag = iCopyMesh.insideFlag | Получить свойство([* ](1.html))  
---|---  
iCopyMesh.insideFlag = insideFlag | Установить свойство ([* ](1.html))  
insideFlag = iCopyMesh.GetInsideFlag() | Получить свойство ([**](2.html))  
iCopyMesh.SetInsideFlag(insideFlag) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
