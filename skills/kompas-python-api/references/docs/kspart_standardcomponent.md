# standardComponent - Признак стандартного компонента

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - свойства ](kspart_props.html) |  Scroll [ [ [ ](kspart_usecolor.html "К следующему разделу")](kspart_props.html "На уровень выше")](kspart_propertyobjecteditable.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- компонент стандартный,  
---|---  
FALSE | \- компонент нестандартный.  
  
Синтаксис Automation:

standardComponent = iPart.standardComponent | Получить свойство ([* ](1.html))  
---|---  
iPart.standardComponent = standardComponent | Установить свойство ([* ](1.html))  
standardComponent = iPart.GetStandardComponent() | Получить свойство ([**](2.html))  
iPart.SetStandardComponent(standardComponent) | Установить свойство ([**](2.html))  
  
Примечание:

Стандартный компонент не имеет Дерева построения и редактируется только через прикладную библиотеку (если он был создан библиотекой, и в нем сохранены имя библиотеки и номер команды редактирования методом [SetUserParam](kspart_setuserparam.html)).

Подразделы:

(отсутствуют)
