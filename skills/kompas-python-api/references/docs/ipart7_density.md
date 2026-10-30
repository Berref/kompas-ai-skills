# Density - Плотность компонента

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - свойства ](ipart7_props.html) |  Scroll [ [ [ ](ipart7_detail.html "К следующему разделу")](ipart7_props.html "На уровень выше")](ipart7_defaultobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Тип данных: double

Синтаксис Automation:

Density = iObject.Density | Получить свойство ([* ](1.html))  
---|---  
Density = iObject.GetDensity() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Density( &Density ) | Получить свойство  
---|---  
  
Значения свойства:

| Плотность компонента (г/куб.мм).  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Для установки плотности необходимо использовать метод [IPart7::SetMaterial](ipart7_setmaterial.html).

Подразделы:

(отсутствуют)
