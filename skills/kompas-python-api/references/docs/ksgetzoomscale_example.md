# ksGetZoomScale - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
double x, y, scale;

if (ksGetZoomScale (&x, &y, &scale)) {

ksZoomScale (100, 100, 2);

Message("Изменен масштаб в окне");

ksZoomScale (x, y, scale);

Message("Предыдущий масштаб");

}

else

MessageBoxResult();
