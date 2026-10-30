# index - Сегмент, задающий направление уклона

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Ребро жесткости (ksRibDefinition, IRibDefinition) ](ksribdefinition.html) > [ksRibDefinition - свойства ](ksribdefinition_props.html) |  Scroll [ [ [ ](ksribdefinition_side.html "К следующему разделу")](ksribdefinition_props.html "На уровень выше")](ksribdefinition_angle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksribdefinition.html)

Тип данных: long

Значения свойства:

0 | \- первое ребро эскиза,  
---|---  
1, 2,… и т.д. | \- последующие ребра эскиза.  
  
Синтаксис Automation:

index = iRib.index | Получить свойство([* ](1.html))  
---|---  
iRib.index = index | Установить свойство ([* ](1.html))  
index = iRib.GetIndex() | Получить свойство ([**](2.html))  
iRib.SetIndex(index) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
