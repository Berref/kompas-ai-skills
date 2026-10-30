# insideFlag - Признак наличия копий внутри сетки

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования компонентов сборки ](nt_copy_asm.html) > [Копия компонентов сборки по параллельной сетке (Интерфейсы ksMeshPartArrayDefinition, IMeshPartArrayDefinition) ](ksmeshpartarraydefinition.html) > [ksMeshPartArrayDefinition - свойства ](ksmeshpartarraydefinition_props.html) |  Scroll [ [ [ ](ksmeshpartarraydefinition_step1.html "К следующему разделу")](ksmeshpartarraydefinition_props.html "На уровень выше")](ksmeshpartarraydefinition_factor2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmeshpartarraydefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- оставлять экземпляры копий во всех узлах сетки,  
---|---  
FALSE | \- оставлять экземпляры копий только по периметру сетки.  
  
Синтаксис Automation:

insideFlag = iMeshArray.insideFlag | Получить свойство([* ](1.html))  
---|---  
iMeshArray.insideFlag = insideFlag | Установить свойство ([* ](1.html))  
insideFlag = iMeshArray.GetInsideFlag() | Получить свойство ([**](2.html))  
iMeshArray.SetInsideFlag(insideFlag) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
