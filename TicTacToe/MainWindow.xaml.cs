using System;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace TTT
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        #region PrivateMembers
        private MarkType[] mResulst;

        private bool mPlayer1Turn;

        private bool mGameEnded;
        #endregion

        #region Constructor
        public MainWindow()
        {
            InitializeComponent();

            NewGame();
        }
        #endregion

        private void NewGame()
        {
            mResulst = new MarkType[9];

            for(int i = 0; i < mResulst.Length; i++)
            {
                mResulst[i] = MarkType.Free;
            }

            mPlayer1Turn = true;

            Container.Children.Cast<Button>().ToList().ForEach(button =>
            {
                button.Content = string.Empty;
                button.Background = Brushes.White;
                button.Foreground = Brushes.Blue;
            });

            mGameEnded = false;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            if(mGameEnded)
            {
                NewGame();
                return;
            }

            var button = (Button)sender;
            var column = Grid.GetColumn(button);
            var row = Grid.GetRow(button);

            var index = column + row * 3;


            if (mResulst[index] != MarkType.Free)
                return;

            mResulst[index] = mPlayer1Turn ? MarkType.Cross : MarkType.Nought;

            button.Content = mPlayer1Turn ? "X" : "O";

            if (!mPlayer1Turn)
                button.Foreground = Brushes.Red;

            mPlayer1Turn ^= true;

            CheckForWinner();
        }

        private void CheckForWinner()
        {
            if(mResulst[0] != MarkType.Free && (mResulst[0] & mResulst[1] & mResulst[2]) == mResulst[0])
            {
                mGameEnded = true;

                Button0_0.Background = Button1_0.Background = Button2_0.Background = Brushes.Green;
            }

            if (mResulst[3] != MarkType.Free && (mResulst[3] & mResulst[4] & mResulst[5]) == mResulst[3])
            {
                mGameEnded = true;

                Button0_1.Background = Button1_1.Background = Button2_1.Background = Brushes.Green;
            }

            if (mResulst[6] != MarkType.Free && (mResulst[6] & mResulst[7] & mResulst[8]) == mResulst[6])
            {
                mGameEnded = true;

                Button0_2.Background = Button1_2.Background = Button2_2.Background = Brushes.Green;
            }

            if (mResulst[0] != MarkType.Free && (mResulst[0] & mResulst[3] & mResulst[6]) == mResulst[0])
            {
                mGameEnded = true;

                Button0_0.Background = Button0_1.Background = Button0_2.Background = Brushes.Green;
            }
            
            if (mResulst[1] != MarkType.Free && (mResulst[1] & mResulst[4] & mResulst[7]) == mResulst[1])
            {
                mGameEnded = true;

                Button1_0.Background = Button1_1.Background = Button1_2.Background = Brushes.Green;
            }

            if (mResulst[2] != MarkType.Free && (mResulst[2] & mResulst[5] & mResulst[8]) == mResulst[2])
            {
                mGameEnded = true;

                Button2_0.Background = Button2_1.Background = Button2_2.Background = Brushes.Green;
            }

            if (mResulst[0] != MarkType.Free && (mResulst[0] & mResulst[4] & mResulst[8]) == mResulst[0])
            {
                mGameEnded = true;

                Button0_0.Background = Button1_1.Background = Button2_2.Background = Brushes.Green;
            }

            if (mResulst[3] != MarkType.Free && (mResulst[2] & mResulst[4] & mResulst[6]) == mResulst[3])
            {
                mGameEnded = true;

                Button0_1.Background = Button1_1.Background = Button0_2.Background = Brushes.Green;
            }

            if (!mResulst.Any(result =>result == MarkType.Free))
            {
                mGameEnded = true;

                Container.Children.Cast<Button>().ToList().ForEach(button =>
                {
                    button.Background = Brushes.Black;
                    button.Content = "TIE";
                });
            }
        }
    }
}
