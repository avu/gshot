/*
#include <gtk/gtk.h>


GdkPixbuf * get_screenshot(){
    GdkPixbuf *screenshot;
    GdkWindow *root_window;
    gint x_orig, y_orig;
    gint width, height;
    root_window = gdk_get_default_root_window ();
   // width = gdk_window_get_width(root_window);
   // height = gdk_window_get_height(root_window);
   // gdk_window_get_origin (root_window, &x_orig, &y_orig);

    screenshot = gdk_pixbuf_get_from_window (root_window, 0, 0, 100, 100);
    return screenshot;
}


gboolean
draw_callback (GtkWidget *widget, cairo_t *cr)
{
    GtkStyleContext *context;
    guint width, height;
    GdkRGBA color;
    GdkPixbuf *screenshot;
    GdkWindow *root_window;

    context = gtk_widget_get_style_context (widget);
    // do your own drawing
    ;

    root_window = gdk_get_default_root_window ();
     width = gdk_window_get_width(root_window);
     height = gdk_window_get_height(root_window);
    fprintf(stderr, "%d %d %d", root_window, width, height);
    // gdk_window_get_origin (root_window, &x_orig, &y_orig);

    screenshot = gdk_pixbuf_get_from_window (root_window, 0, 0, 1000, 1000);

   // gdk_cairo_set_source_pixbuf (cr, pixbuf, 0, 0);
   // cairo_paint (cr);


    width = gtk_widget_get_allocated_width (widget);
    height = gtk_widget_get_allocated_height (widget);

//    gtk_render_background (context, cr, 0, 0, width, height);

    cairo_arc (cr,
               width / 2.0, height / 2.0,
               MIN (width, height) / 2.0,
               0, 2 * G_PI);


   // gtk_style_context_get_color (context,
   //                              gtk_style_context_get_state (context),
   //                              &color);
  //  gdk_cairo_set_source_rgba (cr, &color);

  //  cairo_fill (cr);
    gdk_cairo_set_source_pixbuf(cr, screenshot, 0, 0);
    cairo_fill(cr);
    return FALSE;
}

static void
activate(GtkApplication *app,
         gpointer user_data) {
    GtkWidget *window;
    GtkWidget *area;

    window = gtk_application_window_new(app);
    area = gtk_drawing_area_new();

    g_signal_connect(G_OBJECT(area), "draw",
                     G_CALLBACK(draw_callback),
                     NULL);
    gtk_window_set_title(GTK_WINDOW(window), "Hello GNOME");




    gtk_container_add(GTK_CONTAINER(window), area);
    gtk_widget_show_all(window);
}

int
main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example",
                              G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate",
                     G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return (status);
}
*/
#include <cairo.h>
#include <gdk/gdk.h>

int main (int argc, char *argv[])
{
    gdk_init(&argc, &argv);

    GdkDisplayManager* mgr = gdk_display_manager_get();
    GdkDisplay* display = gdk_display_manager_get_default_display(mgr);
    GdkScreen *screen = gdk_display_get_default_screen(display);
    GdkWindow *root_win = gdk_screen_get_root_window(screen);
    cairo_region_t * r =
    gdk_window_get_clip_region (root_win);
    //GdkWindow *root_win = gdk_get_default_root_window();
    gint width = gdk_window_get_width(root_win);
    gint height = gdk_window_get_height(root_win);

    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32,
                                                          width, height);
    GdkPixbuf *pb = gdk_pixbuf_get_from_window(root_win, 0, 0, width, height);

    cairo_t *cr = cairo_create(surface);
    gdk_cairo_set_source_pixbuf(cr, pb, 0, 0);
    cairo_paint(cr);

    cairo_surface_write_to_png(surface, "image.png");

    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return 0;
}
