# side - Направление формирования ребра

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Ребро жесткости (ksRibDefinition, IRibDefinition) ](ksribdefinition.html) > [ksRibDefinition - свойства ](ksribdefinition_props.html) |  Scroll [ [ [ ](ksribdefinition_methods.html "К следующему разделу")](ksribdefinition_props.html "На уровень выше")](ksribdefinition_index.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksribdefinition.html)

Тип данных: long

Значения свойства:

0 | \- прямое направление в плоскости эскиза,  
---|---  
1 | \- обратное направление в плоскости эскиза,  
2 | \- прямое направление ортогонально эскизу,  
3 | \- обратное направление ортогонально эскизу.  
  
Синтаксис Automation:

side = iRib.side | Получить свойство([* ](1.html))  
---|---  
iRib.side = side | Установить свойство ([* ](1.html))  
side = iRib.GetSide() | Получить свойство ([**](2.html))  
iRib.SetAngle(angle) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
