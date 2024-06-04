#include <linux/module.h>
#include <linux/usb.h>
#include <linux/tty.h>
#include <linux/tty_flip.h>
#include <linux/usb/serial.h>

#define ARDUINO_VENDOR_ID   0x2341
#define ARDUINO_PRODUCT_ID  0x0043

static int arduino_probe(struct usb_interface *interface, const struct usb_device_id *id){

    printk(KERN_INFO "My Arduino UNO has been plugged in");
    return 0;
    
    
}


static void arduino_disconnect(struct usb_interface *interface){

    printk(KERN_INFO "My Arduino UNO has been disconnected");

}


static struct usb_device_id arduino_table[] = {
    { USB_DEVICE(ARDUINO_VENDOR_ID, ARDUINO_PRODUCT_ID) },
    {},
};
MODULE_DEVICE_TABLE(usb, arduino_table);

/*
static void arduino_open(struct tty_struct tty, struct usb_serial_portport)
{
    int retval;
    char data = '1';

    retval = usb_serial_generic_write(port, &data, 1, GFP_KERNEL);
    if (retval < 0) {
        pr_err("Error al enviar '1' al Arduino: %d\n", retval);
    } else {
        pr_info("Enviado '1' al Arduino con éxito\n");
    }
}
*/

/*
static void arduino_close(struct usb_serial_port *port)
{
    // Lógica de cierre del puerto serial
}
*/

static struct usb_driver arduino_driver = {
    .name = "arduino_thing",
    .id_table = arduino_table,
    .probe = arduino_probe,
    //.open = arduino_open,
};

static int __init arduino_init(void)
{   
    printk(KERN_INFO "Contructor of MyDriver start");
    printk(KERN_INFO "Registering Driver with Kernel");
    int ret = usb_register(&arduino_driver);
    printk(KERN_INFO "Registration completed");
    return ret;
}

static void __exit arduino_exit(void)
{
    printk(KERN_INFO "Destructor of MyDriver");
    usb_deregister(&arduino_driver);
    printk(KERN_INFO "Unregistration completed");
}

module_init(arduino_init);
module_exit(arduino_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("JoseRetana");
MODULE_DESCRIPTION("TEST ARDUINO DRIVER");
