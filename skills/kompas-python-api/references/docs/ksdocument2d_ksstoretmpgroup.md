# ksStoreTmpGroup - Вставить временную группу в документ (группа "рассыпается")

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Группы объектов ](bt1732733.html) |  Scroll [ [ [ ](ksdocument2d_ksviewgetobjectarea.html "К следующему разделу")](bt1732733.html "На уровень выше")](ksdocument2d_ksselectgroup.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [StoreTmpGroup](storetmpgroup.html).

Синтаксис Automation:

long ksStoreTmpGroup (long group);

Входной параметр:

group | \- указатель на группу.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Временные объекты не записываются в документ и на экране не отображаются. Они сохраняются только до конца работы создающей их библиотечной команды. Временная группа чаще всего служит для отрисовки фантомного изображения и используется в качестве параметров в методах [ksDocument2D](ksdocument2d_ksplacement.html) и [ksDocument2D::ksCursor](ksdocument2d_kscursor.html). Метод [ksDocument2D::ksStoreTmpGroup](ksdocument2d_ksstoretmpgroup.html) записывает все объекты временной группы в документ (т.е. фиксирует их). Сама же группа получает статус постоянной.

Подразделы:

(отсутствуют)
