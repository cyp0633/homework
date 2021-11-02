package ObjectProgramming.object_manager;

//对象管理器设计
import java.util.*;

public class ConnectionManager {
    static int objCount = 0;
    static Vector<Connection> connectionSet = new Vector<>();

    public static void main(String[] args) {
        String opt = new String();
        Scanner sc = new Scanner(System.in);
        System.out.printf("Want a new connection? Y/N:");
        opt = sc.next();
        if (opt.equalsIgnoreCase("Y")) {
            getNewConnection();
        }
        sc.close();
    }

    static Connection getNewConnection() {
        Iterator<Connection> it = connectionSet.iterator();
        Connection temp;
        while (it.hasNext()) {
            temp = it.next();
            if (temp.askIsFree()) {
                temp.setInUse();
                System.out.printf("已成功申请到连接对象，对象ID：%d", temp.getId());
                return temp;
            }
        }
        if (objCount < 10) {
            objCount++;
            temp = new Connection(objCount);
            connectionSet.add(temp);
            System.out.printf("已成功申请到连接对象，对象ID：%d\n", temp.getId());
            return temp;
        }
        System.out.printf("目前没有空闲连接对象，请稍后再试！\n");
        return null;
    }

    static void freeConnection(Connection c) {
        c.setFree();
    }
}

class Connection {
    private int id;
    private boolean isFree;

    Connection(int i) {
        id = i;
        isFree = true;
    }

    public boolean askIsFree() {
        return isFree;
    }

    public void setInUse() {
        isFree = false;
    }

    public void setFree() {
        isFree = true;
    }

    public int getId() {
        return id;
    }
}
