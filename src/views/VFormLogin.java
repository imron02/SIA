/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package views;

import controllers.FormLogin;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.Window;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

/**
 *
 * @author aim
 */
public class VFormLogin extends JDialog 
{
    private JFrame frame;
    private JPanel panel;
    private JLabel labelUsername;
    private JLabel labelPassword;
    private JTextField usernameTf;
    private JPasswordField passwordTf;
    private JButton buttonLogin;
    private JButton buttonCancel;
    
    public VFormLogin() {
        init_components();
        centre_window(frame);
    }
    
    private void centre_window(Window frame) {
        Dimension dimension = Toolkit.getDefaultToolkit().getScreenSize();
        int x = (int) ((dimension.getWidth() - frame.getWidth()) / 2);
        int y = (int) ((dimension.getHeight() - frame.getHeight()) / 2);
        frame.setLocation(x, y);
    }
    
    private void init_components() {
        frame = new JFrame("Login Application");
        frame.setSize(300, 180);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        panel = new JPanel();
        
        panel.setLayout(null);
        labelUsername = new JLabel("Username: ");
        labelUsername.setBounds(10, 10, 80, 25);
        panel.add(labelUsername);
        
        labelPassword = new JLabel("Passowrd: ");
        labelPassword.setBounds(10, 40, 80, 25);
        panel.add(labelPassword);
        
        usernameTf = new JTextField(20);
        usernameTf.setBounds(100, 10, 160, 25);
        panel.add(usernameTf);
        
        passwordTf = new JPasswordField(20);
        passwordTf.setBounds(100, 40, 160, 25);
        panel.add(passwordTf);
        
        buttonLogin = new JButton("Login");
        buttonLogin.setBounds(10, 110, 80, 25);
        buttonLogin.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                new FormLogin().hello();
            }
        });
        panel.add(buttonLogin);
        
        buttonCancel = new JButton("Cancel");
        buttonCancel.setBounds(180, 110, 80, 25);
        buttonCancel.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                exit_action_performed(e);
            }
        });
        panel.add(buttonCancel);
        
        frame.add(panel);
        frame.setResizable(false);
        frame.setVisible(true);
    }
    
    private void exit_action_performed(ActionEvent e) {
        System.exit(0);
    }
}
