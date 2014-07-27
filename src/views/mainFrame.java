/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package views;

import com.sun.glass.events.KeyEvent;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.GroupLayout;
import javax.swing.ImageIcon;
import javax.swing.JDesktopPane;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.WindowConstants;

/**
 *
 * @author aim
 */
public class mainFrame extends JFrame
{
    private JDesktopPane mdiDesktopPane;
    private JMenuBar menubar;
    private JMenu file;
    private JMenuItem exitItem;
    private ImageIcon exitIcon;
    
    public mainFrame() {
        initComponents();
        setFrame(0.9, true);
    }
    
    private void setFrame(double scala, boolean center) {
        Dimension dimension = Toolkit.getDefaultToolkit().getScreenSize();
        setSize((int)(scala * dimension.getWidth()), (int)(scala * dimension.getHeight()));
        if(center) {
            setLocation( (int)((dimension.getWidth()-getWidth())/2), 
                    (int)((dimension.getHeight()-getHeight())/2) );
        }
    }
    
    private void initComponents() {
        mdiDesktopPane = new JDesktopPane();
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        
        menubar = new JMenuBar();
        file = new JMenu("File");
        file.setMnemonic(KeyEvent.VK_F);
        
        exitIcon = new ImageIcon(this.getClass().getResource("/resources/door_out.png"));
        
        exitItem = new JMenuItem("Exit", exitIcon);
        exitItem.setMnemonic(KeyEvent.VK_E);
        exitItem.setToolTipText("Exit Application");
        
        exitItem.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                ExitMenuItemActionPerformed(e);
            }
        });
        
        file.add(exitItem);
        menubar.add(file);
        
        setJMenuBar(menubar);
        setTitle("Sistem Informasi Akademik");
        
        GroupLayout layout = new GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
                layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addComponent(mdiDesktopPane, GroupLayout.DEFAULT_SIZE, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
                layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addComponent(mdiDesktopPane, GroupLayout.DEFAULT_SIZE, 269, Short.MAX_VALUE)
        );
        
        pack();
    }
    
    private void ExitMenuItemActionPerformed(ActionEvent e) {
        dispose();
    }
}
