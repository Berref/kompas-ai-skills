# sheeting - Тип угла штриховки

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Штриховка (Интерфейс ksHatchParam) ](kshatchparam.html) > [ksHatchParam - свойства ](kshatchparam_props.html) |  Scroll [ [ [ ](kshatchparam_step.html "К следующему разделу")](kshatchparam_props.html "На уровень выше")](kshatchparam_color.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kshatchparam.html)

Тип данных: short

Значения свойства:

0 | \- угол штриховки относительно ее границ сохраняется при повороте границ (используется при изображении накатки на деталях),  
---|---  
1 | \- обычная штриховка (угол штриховки - постоянный).  
  
Синтаксис Automation:

sheeting = iHatchParam.sheeting | Получить свойство ([* ](1.html))  
---|---  
iHatchParam.sheeting = sheeting | Установить свойство ([* ](1.html))  
sheeting = iHatchParam.GetSheeting() | Получить свойство ([**](2.html))  
iHatchParam.SetSheeting(sheeting) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
