# GetViewReference пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//получим указатель на первый вид

reference v = GetViewReference (1);

if (v)

{

ViewParam par;

//возьмем параметры вида

if (GetObjParam (v, &par, sizeof (ViewParam), ALLPARAM))

{

char buf[255];

sprintf (buf,

"Параметры вида\nx = %0.1f, y = %0.1f\nscale=

%0.1f ang =%0.1f state=%d\nname=%s",

par.x, par.y, par.scale, par.ang, par.state, par.name);

Message(buf);

}

}
