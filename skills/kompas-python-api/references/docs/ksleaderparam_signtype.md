# signType - Тип знака на "ножке" линии-выноски

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Линия - выноска ](ch1767016.html) > [Линия - выноска (Интерфейс ksLeaderParam) ](ksleaderparam.html) > [ksLeaderParam - свойства ](ksleaderparam_props.html) |  Scroll [ [ [ ](ksleaderparam_x.html "К следующему разделу")](ksleaderparam_props.html "На уровень выше")](ksleaderparam_ctext3.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksleaderparam.html)

Тип данных: short

Значения свойства:

0 | \- знак отсутствует,  
---|---  
1 | \- знак склеивания,  
2 | \- знак пайки,  
3 | \- знак сшивания,  
4 | \- знак соединения внахлестку металлическими скобами,  
5 | \- знак углового соединения металлическими скобами,  
6 | \- знак монтажного шва.  
  
Синтаксис Automation:

signType = iLeaderParam.signType | Получить свойство ([* ](1.html))  
---|---  
iLeaderParam.signType = signType | Установить свойство ([* ](1.html))  
signType = iLeaderParam.GetSignType() | Получить свойство ([**](2.html))  
iLeaderParam.SetSignType( signType ) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
