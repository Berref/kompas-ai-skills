# multiLayer - Признак размещения объектов из вставленного фрагмента по слоям

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров графических примитивов ](cd1743949.html) > [Вставка фрагмента (Интерфейс ksInsertFragmentParam) ](ksinsertfragmentparam.html) > [ksInsertFragmentParam - свойства ](ksinsertfragmentparam_props.html) |  Scroll [ [ [ ](ksinsertfragmentparam_methods.html "К следующему разделу")](ksinsertfragmentparam_props.html "На уровень выше")](ksinsertfragmentparam_inserttype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksinsertfragmentparam.html)

Тип данных:BOOL.

Значения свойства:

TRUE | \- объекты на тех же слоях, что и во фрагменте-источнике,  
---|---  
FALSE | \- объекты на одном слое.  
  
Синтаксис Automation:

multiLayer = iInsertFragmentParam.multiLayer | Получить свойство ([* ](1.html))  
---|---  
iInsertFragmentParam.multiLayer = multiLayer | Установить свойство ([* ](1.html))  
multiLayer = iInsertFragmentParam.GetMultiLayer() | Получить свойство ([**](2.html))  
iInsertFragmentParam.SetMultiLayer( multiLayer ) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
