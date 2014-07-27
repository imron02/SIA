/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author aim
 */

import com.alee.laf.WebLookAndFeel;
import javax.swing.SwingUtilities;
import views.VFormLogin;

public class main 
{
    public static void main(String[] args) {
        SwingUtilities.invokeLater (new Runnable() {
            public void run ()
            {
                // Install WebLaF as application L&F
                WebLookAndFeel.install ();
                new VFormLogin();
            }
        });
    }
}
