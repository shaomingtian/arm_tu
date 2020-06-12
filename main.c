#include <stdlib.h>
#include <gtk/gtk.h>
//HelloWorld按钮的回调函数，也就是按下HelloWorld按钮会执行这个helloworld函数
static void helloWorld (GtkWidget *wid, GtkWidget *win)
{
  GtkWidget *dialog = NULL;//gtk中的控件
//创建一个dialog窗口，上面的信息为Hello World！
  dialog = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Hello World!");
  gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);//设置窗口的位置
  gtk_dialog_run (GTK_DIALOG (dialog));//运行上面创建的窗口
  gtk_widget_destroy (dialog);//释放窗口的界面内存
}
 
int main (int argc, char *argv[])
{
  GtkWidget *button = NULL;
  GtkWidget *win = NULL;
  GtkWidget *vbox = NULL;
 
  /* Initialize GTK+ *///初始化GTK+ 的代码，这三行代码不要动就可以，自己的代码在下面写
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
  gtk_init (&argc, &argv);
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);
 
  /* Create the main window */
  win = gtk_window_new (GTK_WINDOW_TOPLEVEL);//new出来一个主窗口
  gtk_container_set_border_width (GTK_CONTAINER (win), 8);//设置窗口边缘的大小
  gtk_window_set_title (GTK_WINDOW (win), "Hello World");//设置窗口标题
  gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);//设置窗口位置
  gtk_widget_realize (win);//实现上述窗口
  g_signal_connect (win, "destroy", gtk_main_quit, NULL);//窗口信号连接，点击关闭按钮是会关闭窗口。
 
  /* Create a vertical box with buttons */
  vbox = gtk_vbox_new (TRUE, 6);//创建一个Vbox容器
  gtk_container_add (GTK_CONTAINER (win), vbox);//将创建的容器添加到上述创建的主窗口中
 
  button = gtk_button_new_from_stock (GTK_STOCK_DIALOG_INFO);//创建一个按钮
  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (helloWorld), (gpointer) win);//设置按钮的回调函数，看到callback大家都应该懂这个是回调函数的。
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);//将创建的按钮添加到上述的vbox中
//下面创建关闭按钮，并将关闭按钮的回调函数设置为系统的推出函数gtk_main_quit。
  button = gtk_button_new_from_stock (GTK_STOCK_CLOSE);
  g_signal_connect (button, "clicked", gtk_main_quit, NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
 
  /* Enter the main loop */
  gtk_widget_show_all (win);//显示上述的创建的界面
  gtk_main ();//开始整个主循环。
  return 0;
}
